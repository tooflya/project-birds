package com.tooflya.projectbirds.utils;

import java.util.Calendar;
import java.util.GregorianCalendar;

public class Utils {

	public static int getDayOfMonth() {
		final Calendar now = GregorianCalendar.getInstance();
		return now.get(Calendar.DAY_OF_MONTH);
	}

	public static int getHourOfDay() {
		final Calendar now = GregorianCalendar.getInstance();
		return now.get(Calendar.HOUR_OF_DAY);
	}
}
