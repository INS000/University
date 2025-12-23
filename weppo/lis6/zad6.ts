export type User = {
    typ: 'user'
    name: string;
    age: number;
    occupation?: string;
}

export type Admin = {
    typ: 'admin';
    name: string;
    age: number;
    role?: string;
}

export type Person = User | Admin;

export const persons: Person[] = [ //people not persons
    {
        typ: 'user',
        name: "Jan Kowalski",
        age: 17,
        occupation: "Student"
    },
    {
        typ: 'admin',
        name: "Tomasz Malinowski",
        age: 20,
        role: "Administrator"
    }
];

export function isAdmin(person: Person): person is Admin {
    return person.typ === 'admin';
}

export function isUser(person: Person): person is User {
    return person.typ === 'user';
}


function logPerson(person: Person) {
    let additionalInformation: string = '';
    if (isUser(person)) {
        additionalInformation = person.occupation!;
    }
    if (isAdmin(person)) {
        additionalInformation = person.role!;
    }
    console.log(` - ${person.name}, ${person.age}, ${additionalInformation}`);
}


persons.forEach(logPerson);

