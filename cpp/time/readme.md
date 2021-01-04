# Time in C++

The time functionality in the standard library is kept within the _nested_ namespace `std::chrono` and can be imported from the header `<chrono>`.

In order to use the commands, you either need to fully specify `std::chrono::x` or `using namespace std::chrono;`.

## Duration

A duration has two components, a precision component which is a data type like `long` or `int`, and a `ratio` component. The `ratio` component is a pair of numbers that represents a ratio compared to 1, thus `ratio<1000,1>` would be a "kilo" and `ratio<1,100>` would be a "milli". The default ratio provided is 1.

You can define your own ratios like `using custom = ratio<250,1>` and then utilize those to define your own custom durations `using duri = duration<float, ratio<250,1>`. Besides that, you can utilize the built-in times including `hour`, `minute`, `day`, etc. (with more coming in C++20).

When comparing two durations, like `hour h(24)` and `seconds(360)`, the comparison overload is intelligent enough to compare the relative time, not just the size. Thus even though 360 is larger than 24, `h > s` is still true.

### Constants

You can also define constants using some suffixes available, including `h`, `min`, and `s`. For example, `1h - 16s` to figure out the difference between an hour and sixteen seconds.

### Assignment and Casting

You can assign a duration _as long as no precision is lost_. Thus `milliseconds ms = 2s` is valid but `seconds s = 1999ms` is not. In order to cast with a lost of precision, you must use the `duration_cast()` method like `secconds s = duration_cast<seconds>(1999ms);`.

Additionally, you could define the representation as a floating point like `using floatingseconds = duration<double, ratio<1,1>>;` and the compiler will allow the conversion `floatingsecconds s = 1999ms;`.

## Time Point

As the name implies, `time_point` is a point in time defined by an epoch and an assiciated `duration`. For example, `November 15, 1993` as the epoch and 27 years as the duration.

The `time_point` class yields a `time_since_epoch()` method that provides a duration in whatever unit the clock it was retrieved from defines.

## Clocks

There are two clocks that C++ provides in order to retrieve the current `time_point` using the `now()` static function.

### `system_clock`

Not utilized for accuracy, it is the standard clock used by most people. Its precision is generally in the seconds, and the epoch time is often the classic 1970 time.

There is also a `to_time_t()` method which is unique to the `system_clock`, that is capable of converting a `time_point` to seconds since the Linux epoch time (1970).

### `steady_clock`

Mesaures an elapsed time instead of the "current time" and has a greater precision than `system_clock`. Epoch times may be the system boot time or some other landmark. This particular clock is more useful for timing code segments.

