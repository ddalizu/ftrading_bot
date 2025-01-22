# ftrading_bot
Forex Bot (WIP)

This is a work-in-progress forex trading bot built using C++ and Python, designed to integrate advanced technical indicators and news sentiment analysis for informed trading decisions.

Features (In Progress)
The bot currently supports the following technical analysis indicators implemented in C++:

Exponential Moving Average (EMA): Smoothens price data to identify trends.
MACD: Measures momentum and trend direction.
Bollinger Bands: Identifies volatility and potential overbought/oversold conditions.
RSI (Relative Strength Index): Indicates momentum and possible trend reversals.
Stochastic Oscillator: Determines price position relative to a price range.
Support and Resistance Levels: Detects key price levels for decision-making.
Trendline Analysis: Calculates simple linear regression to identify trends and breakouts.

Upcoming Features

News Sentiment Analysis Agent:
A Python-based AI module for analyzing forex-related news sentiment and incorporating it into trade decisions.

Automated Trade Execution:
Link the bot to a demo/live trading account.

Backtesting Module:
Test the bot's strategies against historical data.

Risk Management Features:
Stop-loss and take-profit strategy implementation.

Dependencies
C++ Libraries:
Standard Template Library (STL): For vector, set, and other utilities.
cmath: For mathematical operations.
algorithm: For numerical operations like min_element and max_element.
Python Libraries (for future modules):
NLTK or spaCy: Natural language processing for sentiment analysis.
Pandas: Data manipulation.
Matplotlib/Plotly: Visualization.
Scikit-learn: For potential regression or AI models.
Setup Instructions

C++ Setup:
Clone the repository:
bash
Copy
Edit
git clone https://github.com/yourusername/forex-bot.git
Navigate to the project directory:
bash
Copy
Edit
cd forex-bot
Compile the C++ code:
bash
Copy
Edit
g++ -o ftrading_bot main.cpp indicator_calculations.cpp
Run the bot:
bash
Copy
Edit
./ftrading_bot
Python Setup (for future modules):
Install dependencies:
bash
Copy
Edit
pip install -r requirements.txt
Usage
Input historical price data for analysis.
Choose the desired indicator for calculation.
Review output for actionable insights (trendlines, breakout detection, etc.).
Contributing
We welcome contributions! Here's how you can get involved:

Fork the repo.
Create a feature branch:
bash
Copy
Edit
git checkout -b feature-name
Commit your changes:
bash
Copy
Edit
git commit -m "Add feature name"
Push to your branch:
bash
Copy
Edit
git push origin feature-name
Submit a pull request.

License
This project is licensed under the MIT License - see the LICENSE file for details.

