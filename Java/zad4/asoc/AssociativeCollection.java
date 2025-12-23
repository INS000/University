package asoc;

public interface AssociativeCollection extends Cloneable, AssocColl {
    void del(String k);
    int size();

    @Override
    default String defaultToString() {
        String[] n = names();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n.length; i++) {
            String key = n[i];
            double val = get(key);
            sb.append("[").append(key).append(":").append(val).append("]");
            if (i < n.length - 1) sb.append(" ");
        }
        return sb.toString();
    }

}
