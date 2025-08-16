class Calculator {
    
    /** 
     * @param {number} value
     */
    constructor(value) {
       this.num = value 
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    add(value){
        this.num = this.num + value ;
        return new Calculator(this.num) ;
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    subtract(value){
        this.num = this.num - value ;
        return new Calculator(this.num) ;
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */  
    multiply(value) {
        this.num = this.num * value ;
        return new Calculator(this.num) ;
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    divide(value) {
        if(value == 0 ){
            throw new Error("Division by zero is not allowed")
        }
        this.num = this.num / value ;
        return new Calculator(this.num) ;
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    power(value) {
        this.num = this.num**value ;
        return new Calculator(this.num) ;
    }
    
    /** 
     * @return {number}
     */
    getResult() {
        return this.num ;
    }
}