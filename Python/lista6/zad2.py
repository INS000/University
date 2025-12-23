import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin
from concurrent.futures import ThreadPoolExecutor, as_completed
from threading import Lock

def crawl(start_page, distance, action):
    visited = set()  # zestaw do śledzenia odwiedzonych stron
    queue = [(start_page, 0)]  # lista z parą (strona, odległość)
    visited_lock = Lock()  # blokada do synchronizacji dostępu do `visited`
    result_queue = []  # lista do przechowywania wyników

    def fetch_page(url, current_distance):
        # Pobranie treści strony i wykonanie `action`
        try:
            response = requests.get(url)
            response.raise_for_status()
            content = response.text
        except requests.RequestException:
            return None, None, None, None  # Zwróć pustą wartość, jeśli nie udało się pobrać strony

        # Zastosowanie funkcji `action` i zwrócenie wyniku
        result = action(content)
        return url, result, content, current_distance

    with ThreadPoolExecutor() as executor:
        while queue:
            # Przetwarzamy wszystkie strony z bieżącej kolejki
            futures = []
            for url, current_distance in queue:
                # Dodajemy do wątków te, które nie były jeszcze odwiedzone
                with visited_lock:
                    if url in visited:
                        continue
                    visited.add(url)  # Oznaczamy stronę jako odwiedzoną
                futures.append(executor.submit(fetch_page, url, current_distance))

            # Oczekujemy na zakończenie zadań
            queue = []  # Opróżniamy kolejkę dla następnej iteracji
            for future in as_completed(futures):
                url, result, content, current_distance = future.result()
                if url is None:
                    continue  # Pomiń, jeśli nie udało się pobrać strony
                # result_queue.append((url, result))  # Dodaj wynik do kolejki wyników
                yield url, result  # Zwróć wynik zamiast dodawać do listy

                # Jeśli osiągnięto maksymalną głębokość, przestań eksplorować odnośniki
                if current_distance >= distance:
                    continue

                # Parsowanie HTML i znajdowanie odnośników na stronie
                soup = BeautifulSoup(content, 'html.parser')
                for link in soup.find_all('a', href=True):
                    link_url = urljoin(url, link['href'])
                    with visited_lock:
                        if link_url not in visited:
                            queue.append((link_url, current_distance + 1))

    return result_queue  # Zwracamy listę wyników

# Przykładowe użycie funkcji
for url, result in crawl("https://sdzwildlifeexplorers.org/animals/python", 1, lambda text: 'Python' in text):
    print(f"{url}: {result}")
