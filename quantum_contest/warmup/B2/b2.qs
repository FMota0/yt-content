namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
        let len = Length(register!);
        for(start in 0..(len - 1)) {
            for(index in 1..(len - start - 1)) {
                let rindex = len - index;
                Controlled X(register![start..(rindex - 1)], register![rindex]);
            }
            X(register![start]);
        }
    }
}