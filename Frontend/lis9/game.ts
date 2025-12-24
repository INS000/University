type Elixir = {
    id: string;
    name: string;
    effect: string;
    sideEffects: string;
    characteristics: string;
    time: string;
    difficulty: string;
    ingredients: { id: string; name: string }[];
    inventors: { id: string; firstName: string; lastName: string }[];
    manufacturer: string;
};

type Spell = {
    id: string;
    name: string;
    incantation: string;
    effect: string;
    canBeVerbal: boolean;
    type: string;
    light: string;
    creator: string;
};

let elixirs: Elixir[] = [];
let spells: Spell[] = [];

let validOption: string | undefined = undefined;

const gameContainer = document.getElementById("game")!;

const Endpoints = {
    ELIXIRS: "Elixirs",
    SPELLS: "Spells",
} as const;

type EndpointType = keyof typeof Endpoints;

async function fetchData<T>(endpoint: (typeof Endpoints)[EndpointType]): Promise<T[]> {
    const response = await fetch(`https://wizard-world-api.herokuapp.com/${endpoint}`);
    if (!response.ok) {
        throw new Error(`Error fetching data from ${endpoint}`);
    }

    return await response.json();
}

async function fetchAllData(): Promise<void> {
    const [elixirsResponse, spellsResponse] = await Promise.all([
        fetchData<Elixir>(Endpoints.ELIXIRS),
        fetchData<Spell>(Endpoints.SPELLS),
    ]);

    elixirs = elixirsResponse.filter((elixir): elixir is Elixir => !!elixir.effect);
    spells = spellsResponse.filter((spell): spell is Spell => !!spell.incantation);
}

function getRandomElements<T>(array: T[], count: number): T[] {
    const indexes: Set<number> = new Set();

    while (indexes.size < count) {
        indexes.add(Math.floor(Math.random() * array.length));
    }

    return Array.from(indexes).map((index) => array[index]);
}

function generateOptions<T extends { name: string }>(randomElements: T[]): {
    rightOption: T;
    options: T[];
} {
    const [rightOption, ...rest] = randomElements;
    const options = [rightOption, ...rest].sort(() =>
        (Math.random() > 0.5 ? 1 : -1)
    );
    return { rightOption, options };
}

function elixirGame(): void {
    const { options, rightOption } = generateOptions(getRandomElements(elixirs, 3));
    validOption = rightOption.name;
    console.log(`Cheat Mode: Right answer is ${validOption}`);
    renderOptions(`Which elixir effect is: "${rightOption.effect}"?`, options.map((elixir) => elixir.name));
}

function spellGame(): void {
    const { options, rightOption } = generateOptions(getRandomElements(spells, 3));
    validOption = rightOption.name;
    console.log(`Cheat Mode: Right answer is ${validOption}`);
    renderOptions(`Which spell incantation is: "${rightOption.incantation}"?`, options.map((spell) => spell.name));
}

function renderOptions(question: string, answers: string[]): void {
    const questionElement = document.getElementById("question");
    if (!gameContainer || !questionElement) {
        throw new Error("Game container or question element not found");
    }

    gameContainer.innerHTML = "";
    questionElement.textContent = question;

    answers.forEach((answer) => {
        const option = document.createElement("button");
        option.textContent = answer;
        gameContainer.appendChild(option);
    });
}

gameContainer.addEventListener("click", (event) => {
    const target = event.target as HTMLElement;
    if (target.tagName === "BUTTON") {
        const selectedOption = target.textContent;
        if (selectedOption === validOption) {
            round();
        } else {
            alert("Wrong answer!");
        }
    }
});

function round(): void {
    const randomGame = Math.random() > 0.5 ? elixirGame : spellGame;
    randomGame();
}

async function startGame(): Promise<void> {
    await fetchAllData();
    round();
}

startGame();
