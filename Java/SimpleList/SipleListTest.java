import structures.SimpleList;
import java.util.Date;
import java.util.Iterator;



public class SipleListTest {
    public static void main(String[] args) {
        testIntegerList();
        testStringList();
        testDateList();
    }

    private static void testIntegerList() {
        System.out.println("Testing Integer List:");
        SimpleList<Integer> intList = new SimpleList<>();
        System.out.println("Empty? " + intList.empty());
        intList.insert(10, 0); // [10]
        System.out.println("Empty? " + intList.empty());
        intList.insert(5, 1);  // [10, 5]
        intList.insert(15, 0); // [15, 10, 5]
        intList.insert(20, 2); // [15, 10, 20, 5]
        System.out.println("Integer List: " + intList);
        System.out.println("Size: " + intList.size());
        System.out.println("Min: " + intList.min());
        System.out.println("Max: " + intList.max());
        System.out.println("Search(20): " + intList.search(20));
        System.out.println("Search(100): " + intList.search(100));
        System.out.println("At(1): " + intList.at(1));
        System.out.println("IndexOf(10): " + intList.index(10));
        System.out.println(intList);
        intList.remove(0);    // [10, 20, 5]
        System.out.println("After removing index 0: " + intList);
        intList.remove((Integer)10);    // [20, 5]
        System.out.println("After removing element 10: " + intList);

        System.out.print("Iterating through list: ");
        int sum = 0;
        for (Integer value : intList) {
            sum += value;
        }
        System.out.println("\nSum: " + sum);
        System.out.println();
    }


    private static void testStringList() {
        System.out.println("Testing String List:");
        SimpleList<String> strList = new SimpleList<>();
        System.out.println("Empty? " + strList.empty());
        strList.insert("banana", 0); // ["banana"]
        System.out.println("Empty? " + strList.empty());
        strList.insert("apple", 1);  // ["banana", "apple"]
        strList.insert("cherry", 0); // ["cherry", "banana", "apple"]
        strList.insert("date", 2);   // ["cherry", "banana", "date", "apple"]
        System.out.println("String List: " + strList);
        System.out.println("Size: " + strList.size());
        System.out.println("Min: " + strList.min());
        System.out.println("Max: " + strList.max());
        System.out.println("Search('date'): " + strList.search("date"));
        System.out.println("Search('fig'): " + strList.search("fig"));
        System.out.println("At(1): " + strList.at(1));
        System.out.println("IndexOf('banana'): " + strList.index("banana"));
        System.out.println(strList);
        strList.remove(0);    // ["banana", "date", "apple"]
        System.out.println("After removing index 0: " + strList);
        strList.remove("banana");    // ["date", "apple"]
        System.out.println("After removing element 'banana': " + strList);
        System.out.println();
    }

    private static void testDateList() {
        System.out.println("Testing Date List:");
        SimpleList<Date> dateList = new SimpleList<>();
        System.out.println("Empty? " + dateList.empty());
        dateList.insert(new Date(1622505600000L), 0); // [June 1 2021]
        System.out.println("Empty? " + dateList.empty());
        dateList.insert(new Date(1609459200000L), 1); // [June 1 2021, Jan 1 2021]
        dateList.insert(new Date(1633046400000L), 0); // [Oct 1 2021, June 1 2021, Jan 1 2021]
        dateList.insert(new Date(1612137600000L), 2); // [Oct 1 2021, June 1 2021, Feb 1 2021, Jan 1 2021]
        System.out.println("Date List: " + dateList);
        System.out.println("Size: " + dateList.size());
        System.out.println("Min: " + dateList.min());
        System.out.println("Max: " + dateList.max());
        System.out.println("Search(Jan 1, 2021): " + dateList.search(new Date(1609459200000L)));
        System.out.println("Search(Mar 1, 2021): " + dateList.search(new Date(1614556800000L)));
        System.out.println("At(1): " + dateList.at(1));
        System.out.println("IndexOf(June 1, 2021): " + dateList.index(new Date(1622505600000L)));
        System.out.println(dateList);
        dateList.remove(0);    // [June 1, 2021, Feb 1, 2021, Jan 1, 2021]
        System.out.println("After removing index 0: " + dateList);
        dateList.remove(new Date(1622505600000L));    // [Feb 1, 2021, Jan 1, 2021]
        System.out.println("After removing element June 1, 2021: " + dateList);
        System.out.println();
    }




}
