#define INFLUX_SERVER ""
#define INFLUX_DB ""
#define WIFI_SSID ""
#define WIFI_PASS ""

/* INTERVAL defines the time between measurements in seconds.
 * INTERVAL_OFFSET is the time (in ms) that one iteration of loop() takes approximately.
 * LOOP_DELAY combines the two values so that the (averaged) effective interval between
 * data points is as close as possible to the configured INTERVAL. We can determine the
 * offset value by executing the following query on our database:
 * SELECT MEAN(elapsed) FROM (SELECT ELAPSED(temp, 1ms) FROM temps ORDER BY DESC LIMIT 100) ORDER BY DESC
 * User code should only ever need to use LOOP_DELAY */
#define INTERVAL (5 * 60)
#define INTERVAL_OFFSET 77
#define LOOP_DELAY ((INTERVAL * 1000) - INTERVAL_OFFSET)
