#ifndef INDICATOR_CALCULATIONS_HPP
#define INDICATOR_CALCULATIONS_HPP

#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

// Use the standard namespace
using namespace std;

// Function declarations
vector<double> calculateEMA(const vector<double>& prices, int period);
vector<vector<double>> calculateMACD(const vector<double>& prices, int shortPeriod, int longPeriod, int signalPeriod);
vector<vector<double>> calculateBollingerBands(const vector<double>& prices, int period, double numStdDev);
vector<double> calculateRSI(const vector<double>& prices, int period);
vector<double> calculateStochastic(const vector<double>& highPrices, const vector<double>& lowPrices, const vector<double>& closePrices, int period);
double calculateSupportLevel(const vector<double>& prices, int period);
double calculateResistanceLevel(const vector<double>& prices, int period);
pair<double, double> calculateTrendline(const vector<double>& prices);
bool detectBreakout(double currentPrice, double trendline);

#endif // INDICATOR_CALCULATIONS_HPP
