package benchmarks.CLEVER.odd.Neq;
public class oldV {
    private int lib(int x) {
        int counter = 0;
        while (x % 2 == 0){
            x = x/2;
            counter++;
        }
        return counter;
    }
    int client(int x){
        if (lib(x)==0){
            return 1;
        }else{
            return 0;
        }
    }
}