namespace Linked_List{
    public class Lista<T>
    {
        public class Element
        {
            public T? val;
            public Element? next, prev;

            public Element(T value){
                val = value;
            }
        };

        private Element? head; 
        private Element? tail;

        public void push_front(T elem)
        {
            Element? pom = new Element(elem);
            if(head == null){
                this.head = pom;
                this.tail = pom;
            }
            else{
                tail!.prev = pom;
                pom.next = tail;
                tail = pom;
            }
        }
        public void push_back(T elem)
        {
            Element? pom = new Element(elem);
            if(head == null){
                this.head = pom;
                this.tail = pom;
            }
            else{
                head.next = pom;
                pom.prev = head;
                head = pom;
            }
        }
        public Element? pop_front()
        {
            Element? pop = tail;
            if(head == null)
                throw new InvalidOperationException("Lista jest pusta");
            if(head == tail){
                head = null;
                tail = null;
                return pop;
            }
            tail!.next!.prev = null;
            tail = tail.next;
            return pop;
    
        }
        public Element? pop_back()
        {
            Element? pop = head;
            if(head == null)
                throw new InvalidOperationException("Lista jest pusta");
            if(head == tail){
                head = null;
                tail = null;
                return pop;
            }
            head.prev!.next = null;
            head = head.prev;
            return pop;
        }
        public void print()
        {
            Element? pom = tail;
            while(pom != null){
                Console.WriteLine(pom.val);
                pom = pom.next;
            }
        }
    };
}

