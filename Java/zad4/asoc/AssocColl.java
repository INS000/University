package asoc;

public interface AssocColl {
    void set(String k, double v);
    double get(String k);
    boolean search(String k);
    String[] names();

    default String defaultToString() {
        String[] n = names();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n.length; i++) {
            String key = n[i];
            double val = get(key);
            sb.append(key).append("=").append(val);
            if (i < n.length - 1)
                sb.append("; ");
        }
        return sb.toString();
    }
}
