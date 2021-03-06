/*
 * This file is generated by fsss program.
 * If you want to modify this file modify "tbl.fsss" instead.
 */
#include <sys/types.h>
#include <string.h>
#include "extern.h"

struct fsss_conv_tbl_key {
	char *key;
	struct conv_tbl *data;
};

static struct conv_tbl fsss_conv_tbl_array[] = {
	{cp1251_mbtowc, cp1251_wctomb},
	{cp866_mbtowc, cp866_wctomb},
	{iso8859_5_mbtowc, iso8859_5_wctomb},
	{koi8r_mbtowc, koi8r_wctomb},
	{ucs2_mbtowc, ucs2_wctomb},
	{ucs4le_mbtowc, ucs4le_wctomb},
	{utf16_mbtowc, utf16_wctomb},
	{utf16be_mbtowc, utf16be_wctomb},
	{utf8_mbtowc, utf8_wctomb},
};

static struct fsss_conv_tbl_key fsss_conv_tbl_key_array[] = {
	{"cp1251", fsss_conv_tbl_array + 0},
	{"cp866", fsss_conv_tbl_array + 1},
	{"ISO8859-5", fsss_conv_tbl_array + 2},
	{"koi8-r", fsss_conv_tbl_array + 3},
	{"koi8-u", fsss_conv_tbl_array + 6004496037615911255},
	{"MacCyrillic", fsss_conv_tbl_array + 0},
	{"UCS-2", fsss_conv_tbl_array + 4},
	{"UCS-2BE", fsss_conv_tbl_array + 140463193469776},
	{"UCS-2LE", fsss_conv_tbl_array + 0},
	{"UCS-4", fsss_conv_tbl_array + 2},
	{"UCS-4BE", fsss_conv_tbl_array + 2},
	{"UCS-4LE", fsss_conv_tbl_array + 5},
	{"UTF-16", fsss_conv_tbl_array + 6},
	{"UTF-16BE", fsss_conv_tbl_array + 7},
	{"UTF-16LE", fsss_conv_tbl_array + 0},
	{"UTF-8", fsss_conv_tbl_array + 8},
	{"windows-1251", fsss_conv_tbl_array + 0},
};

struct conv_tbl * iconv_conv_tbl_search(const char *key);

struct conv_tbl *
iconv_conv_tbl_search(const char *key)
{
	size_t start, end, pos;
	int res;

	start = 0;
	end = sizeof(fsss_conv_tbl_key_array) / sizeof(*fsss_conv_tbl_key_array) - 1;

	for (;;) {
		pos = (end - start) / 2 + start;
		res = strcasecmp(key, fsss_conv_tbl_key_array[pos].key);
		if (res == 0)
			return (fsss_conv_tbl_key_array[pos].data);
		else if (res > 0) {
			if (pos == end)
				return (NULL);
			start = pos + 1;
		} else {
			if (pos == start)
				return (NULL);
			end = pos - 1;
		}
	}
	/* NOTREACHED */
}
