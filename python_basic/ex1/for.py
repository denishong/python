for value in ["가", "나", "다", "라"]:
    print(value)

ripple = [511, 516, 508, 505, 503]
for close in ripple:         # ripple 리스트 안에 있는 close에 대해서 
    print(close)

cur_price = {"BTC": 9010000, "XRP": 511, "DASH": 360000}
for ticker, value in cur_price.items():
    print(ticker, value)
