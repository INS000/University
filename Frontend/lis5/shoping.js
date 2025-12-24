/**
 * @typedef {Object} Product
 * @property {number} id - Id produktu
 * @property {string} name - Nazwa produktu
 * @property {number} quantity - Liczba sztuk do zakupienia
 * @property {Date} purchaseBy - Data, do której produkt powinien być zakupiony
 * @property {boolean} purchased - Status informujący, czy produkt został zakupiony
 * @property {number} [price] - Opcjonalna cena za sztukę (dotyczy tylko zakupionych produktów)
 */

/** @type {Product[]} */
let shoppingList = [];

/**
 * Dodaje nowy produkt do listy zakupów.
 * @param {string} name - Nazwa produktu
 * @param {number} quantity - Liczba sztuk
 * @param {string} dateString - Data zakupu w formacie YYYY-MM-DD
 */
function addProduct(name, quantity, dateString) {
    const id = Math.floor(Math.random() * 1000000);
    shoppingList.push({
        id,
        name,
        quantity,
        purchaseBy: new Date(dateString),
        purchased: false
    });
}

/**
 * Usuwa produkt z listy na podstawie id.
 * @param {number} id - Id produktu do usunięcia
 */
function removeProduct(id) {
    shoppingList = shoppingList.filter(product => product.id !== id);
}

/**
 * Edytuje nazwę produktu na podstawie id.
 * @param {number} id - Id produktu
 * @param {string} newName - Nowa nazwa produktu
 */
function editProductName(id, newName) {
    const product = shoppingList.find(product => product.id === id);
    if (product) product.name = newName;
}

/**
 * Edytuje status zakupu produktu na podstawie id.
 * @param {number} id - Id produktu
 * @param {boolean} newStatus - Nowy status zakupu
 */
function editProductStatus(id, newStatus) {
    const product = shoppingList.find(product => product.id === id);
    if (product) product.purchased = newStatus;
    if (product.price) {
        product.price = undefined; // Resetuje cenę, jeśli produkt został zakupiony
    }
}

/**
 * Edytuje liczbę sztuk produktu na podstawie id.
 * @param {number} id - Id produktu
 * @param {number} newQuantity - Nowa liczba sztuk
 */
function editProductQuantity(id, newQuantity) {
    const product = shoppingList.find(product => product.id === id);
    if (product) product.quantity = newQuantity;
}

/**
 * Edytuje datę zakupu produktu na podstawie id.
 * @param {number} id - Id produktu
 * @param {string} newDateString - Nowa data zakupu w formacie YYYY-MM-DD
 */
function editProductDate(id, newDateString) {
    const product = shoppingList.find(product => product.id === id);
    if (product) product.purchaseBy = new Date(newDateString);
}

/**
 * Zmienia kolejność produktów na liście.
 * @param {number} fromIndex - Aktualny indeks produktu
 * @param {number} toIndex - Docelowy indeks produktu
 */
function moveProduct(fromIndex, toIndex) {
    if (fromIndex < 0 || toIndex < 0 || fromIndex >= shoppingList.length || toIndex >= shoppingList.length) {
        return;
    }
    const [movedProduct] = shoppingList.splice(fromIndex, 1);
    shoppingList.splice(toIndex, 0, movedProduct);
}

/**
 * Zwraca listę produktów do zakupienia dziś.
 * @returns {Product[]} Lista produktów do zakupienia dziś
 */
function getProductsForToday() {
    const today = new Date().toDateString();
    return shoppingList.filter(product => !product.purchased && product.purchaseBy.toDateString() === today);
}

/**
 * Ustawia cenę produktu, jeśli został zakupiony.
 * @param {number} id - Id produktu
 * @param {number} price - Cena za sztukę
 */
function setProductPrice(id, price) {
    const product = shoppingList.find(product => product.id === id);
    if (product && product.purchased) {
        product.price = price;
    }
}

/**
 * Oblicza koszt zakupów danego dnia.
 * @param {string} dateString - Data w formacie YYYY-MM-DD
 * @returns {number} Całkowity koszt zakupów
 */
function calculateTotalCost(dateString) {
    const targetDate = new Date(dateString).toDateString();
    return shoppingList.reduce((total, product) => {
        if (product.purchased && product.purchaseBy.toDateString() === targetDate && product.price !== undefined) {
            return total + product.price * product.quantity;
        }
        return total;
    }, 0);
}

/**
 * Formatuje listę zakupów na podstawie przekazanej funkcji modyfikującej.
 * @param {number[]} ids - Lista id produktów do modyfikacji
 * @param {(product: Product) => void} modifyFunction - Funkcja modyfikująca produkt
 */
function bulkModifyProducts(ids, modifyFunction) {
    shoppingList.forEach(product => {
        if (ids.includes(product.id)) {
            modifyFunction(product);
        }
    });
}

/**
 * Pobiera ID produktu na podstawie jego nazwy.
 * @param {string} productName - Nazwa produktu do wyszukania.
 * @returns {number|null} ID produktu, jeśli istnieje, w przeciwnym razie null.
 */
function getProductIdByName(productName) {
    const product = shoppingList.find(p => p.name === productName);
    return product ? product.id : null;
}


// Testy dla funkcji listy zakupów

// Dodawanie produktów
console.log("Dodawanie produktów...");
addProduct("Mleko", 2, "2025-03-28");
addProduct("Chleb", 1, "2025-03-28");
addProduct("Masło", 1, "2025-03-29");
console.log(shoppingList);

// Usuwanie produktu
console.log("\nUsuwanie produktu Mleko...");
const milkId = shoppingList[0].id;
removeProduct(milkId);
console.log(shoppingList);

// Edycja nazwy
console.log("\nEdycja nazwy Chleb -> Bułka");
const breadId = shoppingList[0].id;
editProductName(breadId, "Bułka");
console.log(shoppingList);

// Edycja statusu zakupu
console.log("\nZmiana statusu Bułka na zakupiony");
editProductStatus(breadId, true);
console.log(shoppingList);

// Edycja liczby sztuk
console.log("\nZmiana liczby sztuk Bułka na 3");
editProductQuantity(breadId, 3);
console.log(shoppingList);

// Edycja daty zakupu
console.log("\nZmiana daty zakupu Bułka na 2025-04-03");
editProductDate(breadId, "2025-04-02");
console.log(shoppingList);

// Przenoszenie produktów
console.log("\nDodanie Jajek i przeniesienie ich na początek listy");
addProduct("Jajka", 12, "2025-03-30");
jajkaId = getProductIdByName("Jajka");
editProductStatus(jajkaId, true);
setProductPrice(jajkaId, 3.5);
moveProduct(2, 0);
console.log(shoppingList);

// Pobieranie produktów do zakupu na dziś
console.log("\nProdukty do zakupienia dzisiaj:");
console.log(getProductsForToday());

// Ustawianie ceny
console.log("\nUstawienie ceny Bułki na 5.5");
setProductPrice(breadId, 5.5);
console.log(shoppingList);

// Obliczanie kosztów zakupów
console.log("\nObliczanie kosztów zakupów na 2025-03-30");
const totalCost = calculateTotalCost("2025-03-30");
console.log("Całkowity koszt: ", totalCost);


// Test funkcji masowej modyfikacji
function increaseQuantity(product) {
    product.quantity += 1;
}
console.log("Test funkcji masowej modyfikacji - zwiększenie liczby sztuk o 1");
const productIds = shoppingList.map(p => p.id);
console.log("Id produktów do modyfikacji: ", productIds);
bulkModifyProducts(productIds, increaseQuantity);
console.log(shoppingList[null]);
