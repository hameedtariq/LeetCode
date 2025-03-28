function divideArray(nums: number[]): boolean {
    const count: Record<number,number> = {};
    for(const num of nums) {
        if (count[num]) count[num]++;
        else count[num] = 1;
    }

    for (const c of Object.values(count)) {
        if(c % 2 != 0) return false;
    }
    return true;
};