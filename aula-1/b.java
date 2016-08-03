import java.lang.*;
import java.util.*;
import java.math.BigInteger;

public class b {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger x = new BigInteger(in.nextLine());
        System.out.println(x.mod(new BigInteger("7")));
    }
}
