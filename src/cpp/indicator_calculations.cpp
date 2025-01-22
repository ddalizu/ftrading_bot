#include "indicator_calculations.hpp"

// Function to calculate Exponential Moving Average (EMA)
vector<double> calculateEMA(const vector<double>& prices, int period) {
    vector<double> ema(prices.size());
    double multiplier = 2.0 / (period + 1);

    // Initialize the first EMA value to the first price
    ema[0] = prices[0];

    // Calculate EMA for the rest of the prices
    for (size_t i = 1; i < prices.size(); ++i) {
        ema[i] = ((prices[i] - ema[i-1]) * multiplier) + ema[i-1];
    }

    return ema;
}

// Function to calculate MACD
vector<vector<double>> calculateMACD(const vector<double>& prices, int shortPeriod, int longPeriod, int signalPeriod) {
    vector<double> shortEMA = calculateEMA(prices, shortPeriod);
    vector<double> longEMA = calculateEMA(prices, longPeriod);
    vector<double> macd(prices.size());
    vector<double> signalLine;
    vector<double> histogram;

    // Calculate MACD line
    for (size_t i = 0; i < prices.size(); ++i) {
        macd[i] = shortEMA[i] - longEMA[i];
    }

    // Calculate Signal line
    signalLine = calculateEMA(macd, signalPeriod);

    // Calculate Histogram
    histogram.resize(prices.size());
    for (size_t i = 0; i < prices.size(); ++i) {
        histogram[i] = macd[i] - signalLine[i];
    }

    return {macd, signalLine, histogram};
}

// Function to calculate Bollinger Bands
vector<vector<double>> calculateBollingerBands(const vector<double>& prices, int period, double numStdDev) {
    vector<double> sma(prices.size());
    vector<double> upperBand(prices.size());
    vector<double> lowerBand(prices.size());

    // Calculate Simple Moving Average (SMA)
    for (size_t i = 0; i <= prices.size() - period; ++i) {
        sma[i + period - 1] = accumulate(prices.begin() + i, prices.begin() + i + period, 0.0) / period;
    }

    // Calculate Standard Deviation and Bollinger Bands
    for (size_t i = 0; i <= prices.size() - period; ++i) {
        double sumSquaredDiffs = 0.0;
        for (size_t j = i; j < i + period; ++j) {
            sumSquaredDiffs += pow(prices[j] - sma[i + period - 1], 2);
        }
        double stddev = sqrt(sumSquaredDiffs / period);
        upperBand[i + period - 1] = sma[i + period - 1] + numStdDev * stddev;
        lowerBand[i + period - 1] = sma[i + period - 1] - numStdDev * stddev;
    }

    return {sma, upperBand, lowerBand};
}

// Function to calculate RSI
vector<double> calculateRSI(const vector<double>& prices, int period) {
    vector<double> rsi(prices.size());
    vector<double> gains(prices.size());
    vector<double> losses(prices.size());

    // Calculate gains and losses
    for (size_t i = 1; i < prices.size(); ++i) {
        double change = prices[i] - prices[i - 1];
        if (change > 0) {
            gains[i] = change;
            losses[i] = 0;
        } else {
            gains[i] = 0;
            losses[i] = -change;
        }
    }

    // Calculate initial average gain and loss
    double avgGain = accumulate(gains.begin() + 1, gains.begin() + period + 1, 0.0) / period;
    double avgLoss = accumulate(losses.begin() + 1, losses.begin() + period + 1, 0.0) / period;

    // Calculate RSI
    for (size_t i = period + 1; i < prices.size(); ++i) {
        avgGain = ((avgGain * (period - 1)) + gains[i]) / period;
        avgLoss = ((avgLoss * (period - 1)) + losses[i]) / period;
        double rs = avgGain / avgLoss;
        rsi[i] = 100 - (100 / (1 + rs));
    }

    return rsi;
}

// Function to calculate Stochastic Oscillator
vector<double> calculateStochastic(const vector<double>& highPrices, const vector<double>& lowPrices, const vector<double>& closePrices, int period) {
    vector<double> stochK(closePrices.size());

    // Calculate %K
    for (size_t i = period - 1; i < closePrices.size(); ++i) {
        double highestHigh = *max_element(highPrices.begin() + i - period + 1, highPrices.begin() + i + 1);
        double lowestLow = *min_element(lowPrices.begin() + i - period + 1, lowPrices.begin() + i + 1);
        stochK[i] = ((closePrices[i] - lowestLow) / (highestHigh - lowestLow)) * 100;
    }

    return stochK;
}

// Function to calculate support level
double calculateSupportLevel(const vector<double>& prices, int period) {
    double supportLevel = *min_element(prices.end() - period, prices.end());
    return supportLevel;
}

// Function to calculate resistance level
double calculateResistanceLevel(const vector<double>& prices, int period) {
    double resistanceLevel = *max_element(prices.end() - period, prices.end());
    return resistanceLevel;
}

// Function to calculate trendline (simple linear regression)
pair<double, double> calculateTrendline(const vector<double>& prices) {
    size_t n = prices.size();
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (size_t i = 0; i < n; ++i) {
        sumX += i;
        sumY += prices[i];
        sumXY += i * prices[i];
        sumX2 += i * i;
    }

    double slope = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double intercept = (sumY - slope * sumX) / n;

    return {slope, intercept};
}

// Function to detect trendline breakout
bool detectBreakout(double currentPrice, double trendlineValue) {
    return currentPrice > trendlineValue;
}
