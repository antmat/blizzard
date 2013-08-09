#ifndef __BLIZZARD_STATISTICS_HPP__
#define __BLIZZARD_STATISTICS_HPP__

#include <stdint.h>
#include <time.h>
#include <string>

namespace blizzard {

struct statistics
{
	enum {TIME_DELTA = 4};

	double last_processed_time;

	volatile int requests_count;
	volatile double resp_time_total;
	volatile double resp_time_min;
	volatile double resp_time_mid;
	volatile double resp_time_max;
	volatile double min_t;
	volatile double max_t;
	volatile double avg_rps;
	volatile size_t eq_ml;
	volatile size_t hq_ml;
	volatile size_t dq_ml;

public:
	volatile size_t easy_queue_len;
	volatile size_t easy_queue_max_len; 
	volatile size_t hard_queue_len;
	volatile size_t hard_queue_max_len; 
	volatile size_t done_queue_len;
	volatile size_t done_queue_max_len;  

	volatile size_t objects_in_http_pool;
	volatile size_t pages_in_http_pool;

	statistics();

	void process(double now);
	void report_response_time(double t);

	void report_easy_queue_len(size_t len);
	void report_hard_queue_len(size_t len);
	void report_done_queue_len(size_t len); 

	double get_min_lifetime() const;
	double get_mid_lifetime() const;
	double get_max_lifetime() const;

	double get_rps() const;

	void generate_xml(std::string &xml, time_t start_time);
};

} /* namespace blizzard */

#endif /* __BLIZZARD_STATISTICS_HPP__ */
