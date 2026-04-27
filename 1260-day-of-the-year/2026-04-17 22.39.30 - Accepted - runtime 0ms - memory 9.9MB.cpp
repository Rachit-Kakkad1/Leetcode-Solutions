class Solution {
public:
    int dayOfYear(string date) {
        int year = (date[0]-'0')*1000 + (date[1]-'0')*100 +
                   (date[2]-'0')*10 + (date[3]-'0');

        int month = (date[5]-'0')*10 + (date[6]-'0');
        int day = (date[8]-'0')*10 + (date[9]-'0');

        int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            days[1] = 29;
        }

        int total = day;

        for (int i = 0; i < month - 1; i++) {
            total += days[i];
        }

        return total;
    }
};