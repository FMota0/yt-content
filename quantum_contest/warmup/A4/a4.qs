namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable flag = 0;
        using (qs = Qubit[2]) {
            unitary(qs);
            if (M(qs[1]) == Zero) {
                set flag = 1;
            }
            ResetAll(qs);
        }
        return flag;
    }
}