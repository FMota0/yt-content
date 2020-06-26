namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable flag = 0;
		using (qs = Qubit[2]) {
			X(qs[1]);
			unitary(qs);
			if (M(qs[0]) == One) {
				set flag = 1;
			}
			ResetAll(qs);
		}
		return flag;
    }
}
