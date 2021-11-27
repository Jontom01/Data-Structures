//this implementation is purposely not that fast
class OAHashTable{
    #tableSize;
    #table = [];
    constructor(tableSize, table){
        this.#tableSize = tableSize;
        this.#table = new Array(this.#tableSize);
    }
    //MULTIPLICATION HASH FUNCTION
    #multiplicationHash(key, flag, i){
        //0 == linear, 1 == quadratic, 2 == double hash
        let V = (Math.sqrt(5.0) - 1)/2;
        let fractionalExtract = key*V;
        let result = Math.floor(this.#tableSize*fractionalExtract);
        let check;
        if(flag == 0){
            check = (result + i) % this.#tableSize;
        } else if(flag == 1){
            check = (result + 701*i + 11*(i*i)) % this.#tableSize
        }else{
            check = (result + Math.pow((key + 11), 3)*i) % this.#tableSize;
        }
        return check;
    }
    //PROBING ALGORITHMS
    #insertProbe(key, flag){
        let i = 0;
        while(i < this.#tableSize){
            let check = this.#multiplicationHash(key, flag, i);
            if(this.#table[check] == undefined){
                this.#table[check] = key;
                break;
            }
            else{ i++; }
        }
        try{
            if(i == this.#tableSize){ 
                throw "value not in table"; 
            }
        }
        catch(msg){
            console.log(msg);
        }
    }
    #search(target, flag){
        let i = 0;
        while(i < this.#tableSize){
            let check = this.#multiplicationHash(target, flag, i);
            if(this.#table[check] == target){
                console.log("Target found")
                break;
            }
            try{
                if(this.#table[check] == undefined){ 
                    throw "value not in table"; 
                }
            }
            catch(msg){
                console.log(msg);
                break;
            }
            i++;
        }
        try{
            if(i == this.#tableSize){ 
                throw "value not in table"; 
            }
        }
        catch(msg){
            console.log(msg);
        }
        return target
    }
    
    
    //PUBLIC METHODS
    tableSize(){
        return this.#tableSize;
    }
    linearInsert(key){
        return this.#insertProbe(key, 0);
    }
    quadraticInsert(key){
        return this.#insertProbe(key, 1);
    }
    doulbeHashInsert(key){
        return this.#insertProbe(key, 2);
    }
    table(){
        return this.#table;
    }
    linearSearch(key){
        return this.#search(key, 0);
    }
    quadraticSearch(key){
        return this.#search(key, 1);
    }
    doubleHashSearch(key){
        return this.#search(key, 2);
    }
}

//MAIN METHOD
let test = new OAHashTable(100)
test.linearInsert(500)
test.linearInsert(120)
test.linearInsert(120)
let x = test.linearSearch(120)
console.log(x)
test.linearSearch(144)
test.quadraticInsert(155)
test.doubleHashSearch(155)
console.log(test.table())
