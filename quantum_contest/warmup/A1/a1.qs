namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable flag = 0;
        using (q = Qubit()){
            unitary(q);
            if (M(q) == One) {
                set flag = 1;
                X(q);
            }
        }
        return flag;
    }
}
