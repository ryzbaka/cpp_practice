void swapByReference(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void swapByAddress(int *x_ptr, int *y_ptr){
    int temp = *x_ptr; //temporarily storing the value at x_ptr address
    *x_ptr = *y_ptr; //storing the value at y_ptr address in the x_ptr address
    *y_ptr = temp;
}

int main(){
    int x = 23;
    int y = 34;
    swapByReference(x,y);
    swapByAddress(&x,&y);
    //swap by value
    int temp = x;
    x = y;
    y=temp;
    return 0;
}