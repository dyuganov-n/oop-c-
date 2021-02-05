import java.util.HashSet;

public class StatCounter {
    private final Character symbol;
    private Integer counter = 0;

    public StatCounter(Character symbol){
        this.symbol = symbol;
        counter = 1;
    }

    public Character getSymbol(){
        return symbol;
    }

    public Integer getCounter() {
        return counter;
    }

    public void increaseCnt() {
        ++counter;
    }

    public void decrease() {
        --counter;
    }

    public boolean equals(StatCounter other) {
        if(other == null) return false;
        return (this == other) || (this.symbol.equals(other.symbol) && this.counter.equals(other.counter));
    }

    //public native int hashCode();
    // использовать хеш код из обджекта
    /*public int hashCode() {
        return (int)symbol;
    }*/
}
