import aiohttp
import asyncio
import json
from prywatne import API_KEY


async def fetch(session, url, headers=None):
    async with session.get(url, headers = headers) as res:
        res = await res.text()
    return res


async def get_fn_stat(nick, url):
    async with aiohttp.ClientSession() as session:
        headers = {'Authorization': API_KEY}
        request = fetch(session, url, headers)
        result = await asyncio.gather(request)
        data = json.loads(result[0])
        id = data['account_id']
        if data['result'] == False:
            return 'Nie znaleziono gracza'
        url2 = f'https://fortniteapi.io/v1/stats?account={id}'
        request = fetch(session, url2, headers)
        result = await asyncio.gather(request)
        data2 = json.loads(result[0])
        return data2['global_stats']

def print_solo_stats(nick):
    url = f'https://fortniteapi.io/v2/lookup?username={nick}'
    stats = asyncio.run(get_fn_stat(nick, url))
    if stats == 'Nie znaleziono gracza':
        print(stats)
        return
    stats = stats['solo']
    print((f"\033[1mStatystyki gracza {nick}:\033[0m"))
    print(f"Zabójstwa: {stats['kills']}")
    print(f"KD: {stats['kd']}")
    print(f"Zwycięstwa: {stats['placetop1']}")
    print(f"Rozegrane mecze: {stats['matchesplayed']}")

async def draw_cards(ile):
    url3 = f'https://deckofcardsapi.com/api/deck/new/draw/?count={ile}'
    async with aiohttp.ClientSession() as session:
        request = fetch(session, url3)
        result = await asyncio.gather(request)
        data = json.loads(result[0])
        return data['cards']

def print_cards(cards):
    for card in cards:
        print(f"{card['value']} of {card['suit']}")


print_solo_stats('YEET-BRUH')
print("\n")
print_cards(asyncio.run(draw_cards(5)))
