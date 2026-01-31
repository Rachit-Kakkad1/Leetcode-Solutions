var findMedianSortedArrays = function(a, b) {
    if (a.length > b.length) return findMedianSortedArrays(b, a);

    let m = a.length, n = b.length;
    let l = 0, r = m;

    while (l <= r) {
        let i = (l + r) >> 1;
        let j = ((m + n + 1) >> 1) - i;

        let al = i ? a[i - 1] : -1e18;
        let ar = i < m ? a[i] : 1e18;
        let bl = j ? b[j - 1] : -1e18;
        let br = j < n ? b[j] : 1e18;

        if (al <= br && bl <= ar) {
            return ((m + n) & 1)
                ? Math.max(al, bl)
                : (Math.max(al, bl) + Math.min(ar, br)) / 2;
        }

        al > br ? r = i - 1 : l = i + 1;
    }
};
