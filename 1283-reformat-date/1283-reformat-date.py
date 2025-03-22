class Solution:
    def reformatDate(self, date: str) -> str:
        month_list = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
        day, month, year = date.split()
        month_format = month_list.index(month) + 1
        month_format = str(month_format) if month_format >= 10 else "0" + str(month_format)
        day_format = str(day[:-2]) if len(day[:-2]) >= 2 else "0" + str(day[:-2])
        return f"{year}-{month_format}-{day_format}"