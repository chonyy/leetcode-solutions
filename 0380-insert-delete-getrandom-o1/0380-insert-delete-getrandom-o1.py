class RandomizedSet:

    def __init__(self):
        self.map = {}
        self.nums = []

    def insert(self, val: int) -> bool:
        if val in self.map:
            return False

        self.nums.append(val)
        self.map[val] = len(self.nums) - 1

        return True

    def remove(self, val: int) -> bool:
        if val not in self.map:
            return False

        lastVal = self.nums[-1]
        removeIdx = self.map[val]
        self.nums[removeIdx], self.nums[len(self.nums) - 1] = self.nums[len(self.nums) - 1], self.nums[removeIdx]

        self.map[lastVal] = removeIdx
        del self.map[val]
        self.nums.pop()

        return True
        

    def getRandom(self) -> int:
        rand = random.randint(0, len(self.nums)-1)
        return self.nums[rand]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()