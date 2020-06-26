namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
        for(index in 1..(Length(register!) - 1)) {
            let rindex = Length(register!) - index;
            Controlled X(register![...(rindex - 1)], register![rindex]);
        }
        X(register![0]);
    }
}