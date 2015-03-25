import java.util.*;

public class DateOfWeekday {

	public static int DateOfWeekday(int date, int weekday) {
        int dayOfWeek = date % 7; // 0 is Sun, 1 is Mon, 2 is Tue, etc.
        if (weekday == 0)
            return date;
        else if (weekday > 0) {
            int weeks = weekday / 7 + (weekday%7 <= dayOfWeek ? 1 : 0);
            if (dayOfWeek == 0 && weekday % 7 == 0)
                weeks--;
            return date - dayOfWeek + weekday % 7 + weeks*7;
        } else {
            weekday = -weekday;
            int weeks = weekday / 7 + (weekday%7 >= dayOfWeek ? 1 : 0);
            if (dayOfWeek == 0 && weekday % 7 == 0)
                weeks--;
            return date - dayOfWeek + weekday % 7 - weeks*7;
        }
        

    }

	public static void main(String[] args) {
		System.out.println(DateOfWeekday(11111, -7));
	}
}