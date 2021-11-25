import java.util.Arrays;
/**
 * Implmentation of an Open Address hash table
 */
public class OAHashTable {
    /**
     * ATTRIBUTES:
     * tableSize - size of the hash table instance
     * table - the instances hash table 
     * currentKey - the key that is currently being inserted
     */
    private int tableSize;
    private String[] table;
    private String currentKey;
//CONSTRUCTOR
    OAHashTable(int tableSize){
        setTableSize(tableSize);
    }
//PRIVATE METHODS
    /**
     * Implementation of multiplication hash method
     * @param key
     * @return modified key
     */
    private int multiplicationHash(int key){
        double V = (Math.sqrt(5.0) - 1)/2;
        double fractionalExtract = key*V;
        double result = Math.floor(tableSize*fractionalExtract);
        //while loop handles result values that are greater than the max integer value
        while(result >= Integer.MAX_VALUE){
            result = Math.floor(result*0.99 - 10000000);
        }
        return (int) result;
    }
    /**
     * Implementation of Sum of Digits hash method
     * @param string
     * @return hashed key
     */
    private int toInt(String string){
        int sum = 0;
        char[] charArr = string.toCharArray();
        for(int i = 0; i < charArr.length; i++){
            sum = (int) Math.floor(sum*1.65 + charArr[i]);
        }
        return sum;
    }
    /**
     * Implementation of linear probing search
     * @param key
     * @return the target project name
     * @throws Exception
     */
    private String linearProbingSearch(int key) throws Exception{
        int i = 0;
        String target = currentKey;
        while(i < tableSize){
            int check = (multiplicationHash(key) + i) % tableSize;
            if(table[check].equals(target)){
                break;
            }
            if(table[check] == ""){ throw new Exception("value not in table"); }
            else{ i++; };
        }
        if(i == tableSize) { throw new Exception("value not in table"); }
        else{ return target; }
        
    }
    /**
     * Implementation of linear probing insert
     * @param key
     * @return the amount of steps taken to insert the current key
     * @throws Exception
     */
    private int linearProbingInsert(int key) throws Exception{
        int i = 0;
        int steps = 0;
        while(i < tableSize){
            steps++;
            int check = (multiplicationHash(key) + i) % tableSize;
            if(table[check] == ""){
                table[check] = currentKey;
                break;
            }
            else{ i++; }
        }
        if(i == tableSize){ throw new Exception("table overflow"); }
        return steps;
    }
    /**
     * Implementation of quadratic probing insert
     * @param key
     * @return the amount of steps taken to insert the current key
     * @throws Exception
     */
    private int quadraticProbingInsert(int key) throws Exception{
        int i = 0;
        int steps = 0;
        while(i < tableSize){
            steps++;
            int check = (multiplicationHash(key) + 9323*i + 9679*(i*i)) % tableSize;
            if(table[check] == ""){
                table[check] = currentKey;
                break;
            }
            i++;
        }
        if(i == tableSize){ throw new Exception("table overflow"); }
        return steps;
    }
    /**
     * Implementation of quadratic probing search
     * @param key
     * @return the target project name
     * @throws Exception
     */
    private String quadraticProbingSearch(int key) throws Exception{
        int i = 0;
        String target = currentKey;
        while(i < tableSize){
            int check = (multiplicationHash(key) + 9323*i + 9679*(i*i)) % tableSize;
            if(table[check].equals(target)){
                break;
            }
            if(table[check] == ""){ throw new Exception("value not in table"); }
            else{ i++; };
        }
        if(i == tableSize) { throw new Exception("value not in table"); }
        else{ return target; }
        
    }
    /**
     * Implementation of double hash probing insert
     * @param key
     * @return the amount of steps taken to insert the current key
     * @throws Exception
     */
    private int doubleHashInsert(int key) throws Exception{
        int i = 0;
        int steps = 0;
        while(i < tableSize){
            steps++;
            int check = (int) ((multiplicationHash(key) + Math.pow((key + 11), 3)*i) % tableSize);
            if(table[check] == ""){
                table[check] = currentKey;
                break;
            }
            else{ i++; }
        }
        if(i == tableSize){ throw new Exception("table overflow"); }
        return steps;
    }
    /**
     * Implementation of double hashing probing search
     * @param key
     * @return the target project name
     * @throws Exception
     */
    private String doubleHashProbingSearch(int key) throws Exception{
        int i = 0;
        String target = currentKey;
        while(i < tableSize){
            int check = (int) ((multiplicationHash(key) + Math.pow((key + 11), 3)*i) % tableSize);
            if(table[check].equals(target)){
                break;
            }
            if(table[check] == ""){ throw new Exception("value not in table"); }
            else{ i++; };
        }
        if(i == tableSize) { throw new Exception("value not in table"); }
        else{ return target; }
        
    }
//PUBLIC METHODS
    /**
     * changes the OAHashTable instances tableSize attribute
     * @param tableSize
     */
    public void setTableSize(int tableSize){
        this.tableSize = tableSize;
        table = new String[tableSize];
        Arrays.fill(table, "");
    }
    /**
     * returns the OAHashTable instances tableSize attribute
     * @param tableSize
     */
    public int getTableSize(){
        return tableSize;
    }
    /**
     * Calls toInt on the inputted key then uses that return value as the input for the linear probing insert method
     * @param projectName
     * @return steps taken to insert value
     * @throws Exception
     */
    public int insertLinear(String projectName) throws Exception{
        currentKey = projectName;
        int key = toInt(projectName);
        return linearProbingInsert(key);
    }
    /**
     * Calls toInt on the inputted key then uses that return value as the input for the double hash probing insert method
     * @param projectName
     * @return steps taken to insert value
     * @throws Exception
     */
    public int insertDoubleHash(String projectName) throws Exception{
        currentKey = projectName;
        int key = toInt(projectName);
        return doubleHashInsert(key);
    }
    /**
     * Calls toInt on the inputted key then uses that return value as the input for the quadratic probing insert method
     * @param projectName
     * @return steps taken to insert value
     * @throws Exception
     */
    public int insertQuadratic(String projectName) throws Exception{
        currentKey = projectName;
        int key = toInt(projectName);
        return quadraticProbingInsert(key);
    }
    /**
     * Calls toInt on the inputted key then uses that return value as the input for the linear probing search method
     * @param projectName
     * @return the target projectName
     * @throws Exception
     */
    public String linearSearch(String projectName) throws Exception{
        currentKey = projectName;
        int key = toInt(projectName);
        String target = linearProbingSearch(key);
        return target;
    }
    /**
     * Calls toInt on the inputted key then uses that return value as the input for the quadratic probing search method
     * @param projectName
     * @return the target projectName
     * @throws Exception
     */
    public String quadraticSearch(String projectName) throws Exception{
        currentKey = projectName;
        int key = toInt(projectName);
        String target = quadraticProbingSearch(key);
        return target;
    }
    /**
     * Calls toInt on the inputted key then uses that return value as the input for the double hash probing search method
     * @param projectName
     * @return the target projectName
     * @throws Exception
     */
    public String doubleHashSearch(String projectName) throws Exception{
        currentKey = projectName;
        int key = toInt(projectName);
        String target = doubleHashProbingSearch(key);
        return target;
    }
    /**
     * Returns the hash table of the OAHashTable instance
     * @return table
     */
    public String[] getTable(){
        return this.table;
    }
}
