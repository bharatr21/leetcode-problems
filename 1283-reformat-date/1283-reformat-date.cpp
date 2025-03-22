class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string> monthMap = 
            {
            {"Jan", "01"},
            {"Feb", "02"}, 
            {"Mar","03"}, 
            {"Apr","04"},
            {"May", "05"},
            {"Jun", "06"},
            {"Jul", "07"},
            {"Aug", "08"},
            {"Sep", "09"},
            {"Oct", "10"},
            {"Nov", "11"},
            {"Dec", "12"}
        };
        stringstream iss(date);
        int day;
        string waste, year, month, dayString;
        iss >> day >> waste >> month >> year;

        if (day < 10) {
            dayString = "0";
        }
        dayString += to_string(day);
        
        return year + "-" + monthMap[month] + "-" + dayString;
    }
};