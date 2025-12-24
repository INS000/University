// zadanie 1

console.log("Zadanie 1:");

console.log(capitalize("alice"));

function capitalize(str) { //fukncje strzałkowe sie nie hoistują
    return str.charAt(0).toUpperCase() + str.slice(1);
};

// zadanie 2

console.log("\nZadanie 2:");

const capitalizeSentence = (sentence) => {
    return sentence
        .split(" ")
        .map(capitalize)
        .join(" ");
}

console.log(capitalizeSentence("alice in wonderland"));

// zadanie 3

console.log("\nZadanie 3:");

const ids = [];

const generateId = () => {
    let id = 0;

    do {
        id++;
    } while (ids.includes(id));

    ids.push(id);
    return id;
};

console.time("generateId");

for (let i = 0; i < 3000; i++) {
    generateId();
}

console.timeEnd("generateId");

const ids2 = new Set();

const generateId2 = () => {
    let id = 0;

    do {
        id++;
    } while (ids2.has(id));

    ids2.add(id);
    return id;
};

console.time("generateId2");

for (let i = 0; i < 3000; i++) {
    generateId2();
}

console.timeEnd("generateId2");

// zadanie 4

console.log("\nZadanie 4:");

const compareObjects = (a, b) => {
    if (typeof a !== typeof b) return false;

    if (typeof a !== "object" || a === null || b === null) {
        return a === b;
    }

    const aKeys = Object.keys(a);
    const bKeys = Object.keys(b);

    if (aKeys.length !== bKeys.length) return false;

    return aKeys.every(key =>
        b.hasOwnProperty(key) && compareObjects(a[key], b[key])
    );
};


const obj1 = {
    name: "Alice",
    age: 25,
    address: {
      city: "Wonderland",
      country: "Fantasy",
    },
  };

const obj2 = {
    name: "Alice",
    age: 25,
    address: {
        city: "Wonderland",
        country: "Fantasy",
    },
};

const obj3 = {
    age: 25,
    address: {
        city: "Wonderland",
        country: "Fantasy",
    },
    name: "Alice",
};

const obj4 = {
    name: "Alice",
    age: 25,
    address: {
        city: "Not Wonderland",
        country: "Fantasy",
    },
};

const obj5 = {
    name: "Alice",
};

console.log("Should be True:", compareObjects(obj1, obj2));
console.log("Should be True:", compareObjects(obj1, obj3));
console.log("Should be False:", compareObjects(obj1, obj4));
console.log("Should be True:", compareObjects(obj2, obj3));
console.log("Should be False:", compareObjects(obj2, obj4));
console.log("Should be False:", compareObjects(obj3, obj4));
console.log("Should be False:", compareObjects(obj1, obj5));
console.log("Should be False:", compareObjects(obj5, obj1));


// zadanie 5

console.log("\nZadanie 5 i 6:");

let library = [];

const addBookToLibrary = (title, author, pages, isAvailable, ratings) => {
    if (typeof title !== "string" || title.trim() === "") throw new Error("Invalid title");
    if (typeof author !== "string" || author.trim() === "") throw new Error("Invalid author");
    if (typeof pages !== "number" || pages <= 0) throw new Error("Invalid pages");
    if (typeof isAvailable !== "boolean") throw new Error("Invalid availability flag");
    if (!Array.isArray(ratings)) throw new Error("Ratings must be an array");

    for (let rating of ratings) {
        if (typeof rating !== "number" || rating < 0 || rating > 5) {
            throw new Error("Invalid rating value");
        }
    }

    library.push({
        title,
        author,
        pages,
        available: isAvailable,
        ratings,
    });
};


// zadanie 6

const testAddingBooks = (testCases) => {
    testCases.forEach(({ testCase, shouldFail }, index) => {
        try {
            addBookToLibrary(...testCase);
            if (shouldFail) {
                console.log(`❌ Test ${index + 1} failed: Expected failure, but succeeded.`);
            } else {
                console.log(`✅ Test ${index + 1} passed.`);
            }
        } catch (e) {
            if (shouldFail) {
                console.log(`✅ Test ${index + 1} passed. Error: ${e.message}`);
            } else {
                console.log(`❌ Test ${index + 1} failed: Unexpected error - ${e.message}`);
            }
        }
    });
};

const testCases = [
    { testCase: ["", "Author", 200, true, []], shouldFail: true },
    { testCase: ["Title", "", 200, true, []], shouldFail: true },
    { testCase: ["Title", "Author", -1, true, []], shouldFail: true },
    { testCase: ["Title", "Author", 200, "yes", []], shouldFail: true },
    { testCase: ["Title", "Author", 200, true, [1, 2, 3, 6]], shouldFail: true },
    {
        testCase: ["Title", "Author", 200, true, [1, 2, 3, "yes"]],
        shouldFail: true,
    },
    { testCase: ["Title", "Author", 200, true, [1, 2, 3, {}]], shouldFail: true },
    { testCase: ["Title", "Author", 200, true, []], shouldFail: false },
    { testCase: ["Title", "Author", 200, true, [1, 2, 3]], shouldFail: false },
    { testCase: ["Title", "Author", 200, true, [1, 2, 3, 4]], shouldFail: false },
    {
        testCase: ["Title", "Author", 200, true, [1, 2, 3, 4, 5]],
        shouldFail: false,
    },
    {
        testCase: ["Title", "Author", 200, true, [1, 2, 3, 4, 5]],
        shouldFail: false,
    },
];

testAddingBooks(testCases);

// zadanie 7

console.log("\nZadanie 7:");

const addBooksToLibrary = (books) => {
    books.forEach(bookArgs => {
        try {
            addBookToLibrary(...bookArgs);
        } catch (e) {
            console.error(`Failed to add book: ${bookArgs[0]} - ${e.message}`);
        }
    });
};

const books = [
    ["Alice in Wonderland", "Lewis Carroll", 200, true, [1, 2, 3]],
    ["1984", "George Orwell", 300, true, [4, 5]],
    ["The Great Gatsby", "F. Scott Fitzgerald", 150, true, [3, 4]],
    ["To Kill a Mockingbird", "Harper Lee", 250, true, [2, 3]],
    ["The Catcher in the Rye", "J.D. Salinger", 200, true, [1, 2]],
    ["The Hobbit", "J.R.R. Tolkien", 300, true, [4, 5]],
    ["Fahrenheit 451", "Ray Bradbury", 200, true, [3, 4]],
    ["Brave New World", "Aldous Huxley", 250, true, [2, 3]],
    ["The Alchemist", "Paulo Coelho", 200, true, [1, 2]],
    ["The Picture of Dorian Gray", "Oscar Wilde", 300, true, [4, 5]],
];

addBooksToLibrary(books);
console.log(library);
