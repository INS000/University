const form = document.getElementById("add-todo-form");
const input = form.querySelector('input[name="todo-name"]');
const list = document.getElementById("todo-list");
const counter = document.getElementById("count");
const clearButton = document.getElementById("todos-clear");

let todos = [];

form.addEventListener("submit", (e) => {
    e.preventDefault();
    const value = input.value.trim();
    if (!value) return;
    todos.push({ name: value, completed: false });
    input.value = "";
    render();
});

clearButton.addEventListener("click", () => {
    todos = [];
    render();
});

function createTodoElement(todo, index) {
    const li = document.createElement("li");
    li.classList.add("todo__container");
    if (todo.completed) li.classList.add("todo__container--completed");

    const nameDiv = document.createElement("div");
    nameDiv.className = "todo-element todo-name";
    nameDiv.textContent = todo.name;
    li.appendChild(nameDiv);

    const upBtn = createButton("↑", "move-up", () => {
    if (index > 0) {
        [todos[index], todos[index - 1]] = [todos[index - 1], todos[index]];
        render();
    }
    });

    const downBtn = createButton("↓", "move-down", () => {
    if (index < todos.length - 1) {
        [todos[index], todos[index + 1]] = [todos[index + 1], todos[index]];
        render();
    }
    });

    const toggleBtn = createButton(todo.completed ? "Revert" : "Done", "", () => {
        todos[index].completed = !todos[index].completed;
        render();
    });

    const removeBtn = createButton("Remove", "", () => {
        todos.splice(index, 1);
        render();
    });

    li.appendChild(upBtn);
    li.appendChild(downBtn);
    li.appendChild(toggleBtn);
    li.appendChild(removeBtn);

    return li;
}

function createButton(text, extraClass, onClick) {
    const btn = document.createElement("button");
    btn.className = `todo-element todo-button ${extraClass}`;
    btn.textContent = text;
    btn.addEventListener("click", onClick);
    return btn;
}

function render() {
    list.innerHTML = "";
    let remaining = 0;

    todos.forEach((todo, index) => {
        if (!todo.completed) remaining++;
        list.appendChild(createTodoElement(todo, index));
    });

    counter.textContent = remaining;
}

// Dodanie elementów z HTML do tablicy todos
window.addEventListener("DOMContentLoaded", () => {
    const staticTodos = Array.from(document.querySelectorAll("#todo-list li"));
    staticTodos.forEach((li) => {
        const name = li.querySelector(".todo-name")?.textContent || "Untitled";
        const completed = li.classList.contains("todo__container--completed");
        todos.push({ name, completed });
    });
    render();
});
