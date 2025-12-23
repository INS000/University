import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin
from concurrent.futures import ThreadPoolExecutor, as_completed
from threading import Lock

def crawl(start_page, distance, action):
    visited = set()
    queue = [(start_page, 0)]
    lock = Lock()

    def process_page(current_page, current_distance):
        try:
            response = requests.get(current_page)
            response.raise_for_status()
            content = response.text
        except requests.exceptions.RequestException as e:
            return None, None, None, None

        result = action(content)
        return (current_page, result, content, current_distance)


    with ThreadPoolExecutor() as executor:
        while queue:
            futures = []
            for current_page, current_distance in queue:
                with lock:
                    if current_page in visited or current_distance > distance:
                        continue
                    visited.add(current_page)
                futures.append(executor.submit(process_page, current_page, current_distance))

            queue = []

            for future in as_completed(futures):
                result = future.result()
                if result:
                    url, res, con, dist = result
                    if url is None:
                        print(f"Error while processing")
                        continue
                    yield url, res

                    if dist >= distance:
                        continue

                    soup = BeautifulSoup(con, 'html.parser')
                    for link in soup.find_all('a', href=True):
                        absolute_link = urljoin(url, link.get('href'))
                        with lock:
                            if absolute_link not in visited:
                                queue.append((absolute_link, dist + 1))


for url, result in crawl("https://sdzwildlifeexplorers.org/animals/python", 1, lambda text: 'Python' in text):
    print(f"{url}: {result}")
