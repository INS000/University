package structures;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class SimpleList<T extends Comparable<T>> implements SimpleSequence<T>, Iterable<T> {
    private class SimpleNode {
        T data;
        SimpleNode next;
        SimpleNode prev;

        SimpleNode(T data) {
            this.data = data;
            this.next = null;
            this.prev = null;
        }
    }

    private SimpleNode head;
    private int size;
    private int modCount;

    private SimpleNode getNodeAt(int pos) {
        if (pos < 0 || pos >= size) {
            throw new IndexOutOfBoundsException("Position out of bounds");
        }

        SimpleNode current = head;
        for (int i = 0; i < pos; i++) {
            current = current.next;
        }
        return current;
    }

    @Override
    public void insert(T el, int pos) {
        if(el == null) {
            throw new IllegalArgumentException("Element cannot be null");
        }

        if (pos < 0 || pos > size) {
            throw new IndexOutOfBoundsException("Position out of bounds");
        }

        SimpleNode newNode = new SimpleNode(el);
        if (head == null) {
            head = newNode;
        } else if (pos == 0) {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        } else {
            SimpleNode current = getNodeAt(pos - 1);
            newNode.next = current.next;
            newNode.prev = current;
            if (current.next != null) {
                current.next.prev = newNode;
            }
            current.next = newNode;
        }

        size++;
        modCount++;
    }

    private void unlinkNode(SimpleNode node) {
        if (node.prev != null) {
            node.prev.next = node.next;
        } else {
            head = node.next;
        }
        if (node.next != null) {
            node.next.prev = node.prev;
        }
    }

    @Override
    public boolean remove(T el) {
        if (el == null) {
            throw new IllegalArgumentException("Element cannot be null");
        }

        SimpleNode current = head;
        while (current != null) {
            if (current.data.equals(el)) {
                unlinkNode(current);
                size--;
                modCount++;
                return true;
            }
            current = current.next;
        }
        return false;
    }

    @Override
    public T remove(int pos) {
        if (pos < 0 || pos >= size) {
            throw new IndexOutOfBoundsException("Position out of bounds");
        }

        SimpleNode current = getNodeAt(pos);

        T data = current.data;
        unlinkNode(current);
        size--;
        modCount++;
        return data;
    }

    @Override
    public T min() {
        if (empty()) {
            throw new NoSuchElementException("List is empty");
        }

        T min = head.data;
        SimpleNode current = head.next;

        while (current != null) {
            if (current.data.compareTo(min) < 0) {
                min = current.data;
            }
            current = current.next;
        }
        return min;
    }

    @Override
    public T max() {
        if (empty()) {
            throw new NoSuchElementException("List is empty");
        }

        T max = head.data;
        SimpleNode current = head.next;

        while (current != null) {
            if (current.data.compareTo(max) > 0) {
                max = current.data;
            }
            current = current.next;
        }
        return max;
    }

    @Override
    public boolean search(T el) {
        if (el == null) {
            throw new IllegalArgumentException("Element cannot be null");
        }

        return index(el) != -1;
    }

    @Override
    public T at(int pos) {
        return getNodeAt(pos).data;
    }

    @Override
    public int index(T el) {
        if (el == null) {
            throw new IllegalArgumentException("Element cannot be null");
        }

        SimpleNode current = head;
        int index = 0;

        while (current != null) {
            if (current.data.equals(el)) {
                return index;
            }
            current = current.next;
            index++;
        }
        return -1;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean empty() {
        return size == 0;
    }

    private class SimpleListIterator implements Iterator<T> {
        private SimpleNode current;
        private final int expectedModCount;

        SimpleListIterator() {
            this.current = head;
            this.expectedModCount = modCount;
        }

        @Override
        public boolean hasNext() {
            if (expectedModCount != modCount) {
                throw new IllegalStateException("List structure modified during iteration");
            }
            return current != null;
        }

        @Override
        public T next() {
            if (!hasNext()) {
                throw new NoSuchElementException("No more elements in the list");
            }
            T data = current.data;
            current = current.next;
            return data;
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("[");

        SimpleNode current = head;
        while (current != null) {
            sb.append(current.data);
            if (current.next != null) {
                sb.append(", ");
            }
            current = current.next;
        }

        sb.append("]");
        return sb.toString();
    }

    public Iterator<T> iterator() {
        return new SimpleListIterator();
    }
}
