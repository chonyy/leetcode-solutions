class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        // <x/y>
        // try each slots
        // overhead = 3 * slots + x + y
        //   x = 1 + 2 + ... + slots
        //   y = slots * slots
        // look for slots * limit - overhead >= n

        int slots = 1;
        int xSlots = 1;

        while (true) {
            if (3 + (int)to_string(slots).size() * 2 >= limit)
                return {};

            if (canUseSlots(slots, message, limit, xSlots))
                break;

            slots++;
            xSlots += to_string(slots).size();
        }

        vector<string> res;
        int idx = 0;

        for (int i = 1; i <= slots; i ++) {
            string x = to_string(i);
            string y = to_string(slots);
            string suffix = "<" + x + "/" + y + ">";
            int remain = limit - suffix.size();
            string cut = message.substr(idx, remain);
            idx += remain;

            res.push_back(cut + suffix);
        }

        return res;
    }

    bool canUseSlots(int slots, string& message, int limit, int xSlots) {
        int y = to_string(slots).size() * slots;
        int overhead = xSlots + y + 3 * slots;
        
        return slots * limit - overhead >= message.size();
    }
};
