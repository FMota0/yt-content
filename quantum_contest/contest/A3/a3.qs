namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
		mutable flag = 0;
		using (q = Qubit()) {
			X(q);
			unitary(q);
			Z(q);
			unitary(q);
			if (M(q) == Zero) {

			} else {
				set flag = 1;
			}
			Reset(q);
		}
		return flag;
    }
}