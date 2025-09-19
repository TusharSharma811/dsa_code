class Spreadsheet {
    
    vector<vector<int>> grid ;
    int rows ;
public:
    Spreadsheet(int rows) {
        this->rows = rows ;
        grid =  vector<vector<int>>(rows+1 , vector<int>(26 , 0)) ;
    }
    
    void setCell(string cell, int value) {
        pair<int ,int > pos ;
        if(cell.empty() || isalpha(cell[0])) pos = {-1 , -1} ;
        
         int columnIndex = toupper(cell[0]) - 'A';
        int rowIndex = stoi(cell.substr(1)) ;
        
        pos = {rowIndex , columnIndex} ;
        
        if(isvalidcell(pos)){
            grid[pos.first][pos.second] = value ;
        }
    }
    
    void resetCell(string cell) {
         pair<int ,int > pos ;
         if(cell.empty() || isalpha(cell[0])) pos = {-1 , -1} ;
        
         int columnIndex = toupper(cell[0]) - 'A';
        int rowIndex = stoi(cell.substr(1)) ;
        
        pos = {rowIndex , columnIndex} ;
        
        if(isvalidcell(pos)){
            grid[pos.first][pos.second] = 0 ;
        }
    }
    
    int getValue(string formula) {
        if(formula.empty() || formula[0] != '=')return 0 ;
        string exp = formula.substr(1) ;
         int sum = 0, i = 0, n = exp.size();

    while (i < n) {
        int j = i;
        while (j < n && exp[j] != '+') j++; 

        sum += parsevalue(exp.substr(i, j - i)); 
        
        i = j + 1; 
    }

    return sum;
    }
    
    int parsevalue(string token){
        if(isalpha(token[0]) && token.length() > 0){
            pair<int ,int > pos ;
         if(token.empty() || isalpha(token[0])) pos = {-1 , -1} ;
        
            int columnIndex = toupper(token[0]) - 'A';
            int rowIndex = stoi(token.substr(1)) ;
        
        pos = {rowIndex , columnIndex} ;
            
        if(isvalidcell(pos)){
            return grid[pos.first][pos.second] ;
        }
            else{
                return 0 ;
            }
        }
        
        else{
            return stoi(token) ;
        }
    }
    
    bool isvalidcell(pair<int , int> cell){
        return cell.first>0 && cell.first < grid.size() && cell.second >=0 &&  cell.second <26 ; 
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */