import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin

def crawl(start_page, distance, action):
    visited = set()
    queue = [(start_page, 0)]

    while queue:
        current_page, current_distance = queue.pop(0)

        if current_page in visited or current_distance > distance:
            continue

        visited.add(current_page)

        try:
            response = requests.get(current_page)
            response.raise_for_status()
            content = response.text
        except requests.exceptions.RequestException as e:
            print(f"Error while processing {current_page}: {e}")
            continue

        result = action(content)
        yield (current_page, result)

        soup = BeautifulSoup(content, 'html.parser')
        for link in soup.find_all('a', href=True):
            absolute_link = urljoin(current_page, link.get('href'))
            if absolute_link not in visited:
                queue.append((absolute_link, current_distance + 1))


for url, result in crawl("https://sdzwildlifeexplorers.org/animals/python", 1, lambda text: 'Python' in text):
    print(f"{url}: {result}")
