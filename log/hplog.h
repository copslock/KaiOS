
#ifndef HPLOG_H_
#define HPLOG_H_

#undef hpfilename
#include <string.h>
#define hpfilename(x) strrchr(x,'/')?strrchr(x,'/')+1:x

#undef HP_LOG_TAG
#define HP_LOG_TAG "hpandroid"

#undef hplog
#include <android/log.h>
#define hplog(fmt, ...) \
  __android_log_print(ANDROID_LOG_DEBUG, \
                      HP_LOG_TAG, \
                      "-@- gecko %s::%s: -> " fmt , hpfilename(__FILE__),  __FUNCTION__, ##__VA_ARGS__)

/*
 * Retrieve a ASCII char * from an nsString object.
 * If nsString is empty, will return an empty C string
 * This char * is only valid during the lifetime of the calling function.
 */
#define hp_nsString_CSTR(x) (char*)(NS_LossyConvertUTF16toASCII((x)).get())

#define hp_nsAString_TO_CSTR(s) (char*)(ToNewUTF8String(s))


/*
 * Retrieve a ASCII char * from an nsString object.
 * If nsString is empty or void return nullptr, else returns a char *.
 * This char * is only valid during the lifetime of the calling function.
 * NC stands for Null Check
 */
#define hp_nsString_TO_CSTR_NC(s) ((s).IsEmpty() == true) ? nullptr : hp_nsString_CSTR((s))

/**
 * Convert a ASCII char * to an nsString object
 */
#define hp_CSTR_TO_nsString(c, s) (((c) != nullptr) ? s.AssignASCII((c)) : (s).SetIsVoid(true))

/*
 * Retrieve a ASCII char * from an nsCString object.
 * If nsCString is empty, will return an emtpy C string
 * This char * is only valid during the lifetime of the calling function.
 */
#define hp_nsCString_TO_CSTR(s) ((s).get())

/*
 * Retrieve a ASCII char * from an nsCString object.
 * If nsCString is empty or void return nullptr, else returns a char *.
 * This char * is only valid during the lifetime of the calling function.
 * NC stands for Null Check
 */
#define hp_nsCString_TO_CSTR_NC(s) ((s).IsEmpty() == true) ? nullptr : hp_nsCString_TO_CSTR((s))

/*
 * Retrieve a ASCII char * from an nsACString object.
 * If nsACString is empty, will return an emtpy C string
 * This char * is only valid during the lifetime of the calling function.
 */
#define hp_nsACString_TO_CSTR(s) (nsAutoCString((s)).get())

/*
 * Retrieve a ASCII char * from an nsACString object.
 * If nsACString is empty or void return nullptr, else returns a char *.
 * This char * is only valid during the lifetime of the calling function.
 * NC stands for Null Check
 */
#define hp_nsACString_TO_CSTR_NC(s) ((s).IsEmpty() == true) ? nullptr : hp_nsACString_TO_CSTR((s))


#endif /* HPLOG_H_ */

