/*
 * An object of type List represents a list of strings.  Methods
 * are provided to insert a string into the list, to get all strings in list,
 * to get the number of occurences of each string in the list, and to 
 * print each word lexicographically along with its number of occurences.
 */

import java.util.Scanner;

public class Ten2
{
    public static void main(String [] arg)
    {
        // 1. Get input from command line
        Scanner input = new Scanner(System.in);
        
        // 2. Make the empty List object        
        List sortedList = new List();
        
        // 3. Create string variable representing the first word from input
        String word = nextWord(input);
        
        // 4. Loop through while there is another word from input, 
         // insert the current word into List, move to the next word
        while (word != null) {
            sortedList.insert(word);
            word = nextWord(input);
        }

        // 5. Print the words and relative frequency
        sortedList.printWords();
    }

    // method to return the cleaned-up string representing a word from input
    private static String nextWord(Scanner input)
    {   
        // return null if there are no more words
        if (input.hasNext() == false )
            return null;
        // take next element, convert to lowercase, store in s
        else { 
            String s = input.next().toLowerCase() ;
            // empty string
            String token = "";
            // loop through s and concatonate chars onto token
            for (int i =0; i < s.length(); i++) {
                if (Character.isLetter(s.charAt(i)) == true)
                    token = token + s.charAt(i);
                else if (s.charAt(i) == '\'' )
                    token = token + s.charAt(i);
                else if (s.charAt(i) == '-')
                    token = token + s.charAt(i);
            }
            return token; 
        }      
    }
}

class List
{
    /*
     * Internally, the list of strings is represented by a linked chain 
     * of nodes belonging to the class ListNode. The strings are stored
     * in lexicographical order.
     */
    private static class ListNode
    {
        // instance variables for ListNode objects
        public String word;
        public ListNode next;
        public int count;
        
        // Listnode constructor               
        public ListNode(String w, ListNode nxt)
        {  
            word = w; // token from nextWord()
            next = nxt; // link to next ListNode
            count = 1; // number of word occurences
        }
    }
    
    // instance variables for List object
    private ListNode first;
    private int numWords;

    // constructor postcondition: creates new Listnode storing object
    public List()
    { 
        first = null; // empty list when created
        numWords = 0; // counter for nodes in list
    }
        
    // Insert a specified word into the list
    public void insert(String word)
    {    
        // check if first is null
        if (first == null) {
            ListNode newNode;
            newNode = addNode(word, null);
            first = newNode;          
        }   
        
        // else if (first is not null) check if word matches first word in List
        else if (word.equals(first.word)) {
            // increase count
            first.count++;
            }
        
        /*
         * Fist two cases of empty list and word already existing
         * handled above. now by using compareTo() 
         * method between the words, the insertion postion can be determined.
         * Links between ListNode variables current, previous, and first need 
         * to be modified in order to maintain order in the list.
         */        

        // else (first is not null && doesn't match first word) 
        else {  
            ListNode newNode;
            ListNode current;
            current = first;
            ListNode previous;
            previous = null;
            int cmp =  word.compareTo(current.word);

            // loop as long as value comparing to is positive. when compareTo() returns
             // positive this means the "word" parameter is greater than the word in the list 
            while ((cmp > 0) && (current.next != null)) {
                previous = current;    
                current = current.next;
                cmp =  word.compareTo(current.word);
            }

            // insert after current at end of list
            if ((cmp >0 && current.next == null)) {
                newNode = addNode(word, null);
                current.next = newNode;
            }
            
            // increments count when word already exists
            else if (cmp == 0) {
                current.count++;
            }
            
            // else (cmp < 0) we insert BEFORE current
            else { 
                newNode = addNode(word, current);
                
                // first node in list comes after new word
                if (previous == null) {
                    first = newNode;       
                }         
                
                else {
                    // inserting new word in middle of list
                    previous.next = newNode;
                }
            }       
        }
    }

    // method to add new ListNode and increase counter
    private ListNode addNode(String word, ListNode next)
    {
        ListNode newNode = new ListNode(word, next);
        numWords++;
        return newNode;
    }

    
    // Returns a string array that contains all the words in the list.  
    public String[] getWords() 
    {
        String[] Words = new String[numWords];
        ListNode current = first;
        int i =0;
        
        while (current != null) {     
            Words[i] = current.word;
            current = current.next;
            i++;
        }
        return Words;
    }   
    
    // Returns an int array that contains the relative requency of each word in the list.  
    public int[] getNumbers()
    {
        int[] Numbers = new int[numWords];
        ListNode current = first;
        int i =0;

        while (current != null) {
            Numbers[i] = current.count;
            current = current.next;
            i++;
        }
        return Numbers;
    }

    // Outputs the string array and int array containing all the words and relative frequencies.
    public void printWords()
    {
        int[] Numbers = getNumbers();
        String[] Words = getWords();

        System.out.printf("%-20s \t %s\n","Word", "Occurs");
        System.out.printf("%-20s \t %s\n","====", "======");
        
        for (int i =0; i < numWords; i++) { 
            System.out.printf("%-20s \t %d\n", Words[i], Numbers[i]);
        }
    }      
}   
 




