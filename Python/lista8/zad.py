import matplotlib.pyplot as plt
import requests
import numpy as np
from sklearn.linear_model import LinearRegression
import json
from datetime import datetime

res2022 = requests.get("https://api.nbp.pl/api/exchangerates/rates/A/EUR/2022-01-01/2022-12-31/?format=json")
res2023 = requests.get("https://api.nbp.pl/api/exchangerates/rates/A/EUR/2023-01-01/2023-12-31/?format=json")
res2024 = requests.get("https://api.nbp.pl/api/exchangerates/rates/A/EUR/2024-01-01/2024-11-30/?format=json")

data2022 = res2022.json()
data2023 = res2023.json()
data2024 = res2024.json()

months2022 = [0 for _ in range(12)]
months2023 = [0 for _ in range(12)]
months2024 = [0 for _ in range(11)]


for day in data2022['rates']:
    months2022[int(day['effectiveDate'][5:7])-1] += day['mid']

for day in data2023['rates']:
    months2023[int(day['effectiveDate'][5:7])-1] += day['mid']

for day in data2024['rates']:
    months2024[int(day['effectiveDate'][5:7])-1] += day['mid']

days = [31, 30, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30]

for i in range(12):
    months2022[i] /= days[i]
    months2023[i] /= days[i]

for i in range(11):
    months2024[i] /= days[i]

months2024[1] = months2024[1] * 29 / 28

X = np.array(range(1, 25)).reshape(-1, 1)
y = np.array(months2022 + months2023)

model = LinearRegression()
model.fit(X, y)

prediction2024 = model.predict(np.array(range(25, 37)).reshape(-1, 1))




plt.plot(range(1, 13), months2022, label='2022', color='red', marker='o')
plt.plot(range(1, 13), months2023, label='2023', color='blue', marker='o')
plt.plot(range(1, 12), months2024, label='2024-data', color='green', marker='o')
plt.plot(range(1, 13), prediction2024, label='2024-predict', color='orange', marker='o')
plt.legend()
plt.xlabel('Miesiące')
plt.ylabel('Średni kurs EUR')
plt.title('Średni kurs EUR w 2022, 2023, 2024 roku')
plt.grid()
plt.xticks(range(1, 13))
plt.show()


### 2gie dane
with open('api.json', 'r') as file:
    data = json.load(file)

data = data['market-price']

months2022 = [0 for _ in range(12)]
months2023 = [0 for _ in range(12)]
months2024 = [0 for _ in range(12)]

for i in data:
    day = datetime.fromtimestamp(i['x'] / 1000)
    if day.year == 2022:
        months2022[day.month-1] += i['y']
    elif day.year == 2023:
        months2023[day.month-1] += i['y']
    elif day.year == 2024:
        months2024[day.month-1] += i['y']

for i in range(12):
    months2022[i] /= days[i]
    months2023[i] /= days[i]
    months2024[i] /= days[i]

months2024[1] = months2024[1] * 29 / 28
months2024.pop()

X = np.array(range(1, 25)).reshape(-1, 1)
y = np.array(months2022 + months2023)

model = LinearRegression()
model.fit(X, y)

prediction2024 = model.predict(np.array(range(25, 37)).reshape(-1, 1))

plt.plot(range(1, 13), months2022, label='2022', color='red', marker='o')
plt.plot(range(1, 13), months2023, label='2023', color='blue', marker='o')
plt.plot(range(1, 12), months2024, label='2024-data', color='green', marker='o')
plt.plot(range(1, 13), prediction2024, label='2024-predict', color='orange', marker='o')
plt.legend()
plt.xlabel('Miesiące')
plt.ylabel('Cena Bitcoin')
plt.title('Cena Bitcoin w 2022, 2023, 2024 roku')
plt.grid()
plt.xticks(range(1, 13))
plt.show()
