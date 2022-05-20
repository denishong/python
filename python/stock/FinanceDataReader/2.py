import FinanceDataReader as fdr
import mplfinance as mpf

code = "201490"
start_date='2020-11-01'
end_date='2021-12-30'

df=fdr.DataReader(code,start_date,end_date)
kwargs=dict(title='customized chart', type='candle', mav=(2,4,6), volume=True,ylabel='ohlc candle')
mc=mpf.make_marketcolors(up='r',down='b',inherit=True)
s=mpf.make_mpf_style(marketcolors=mc)
mpf.plot(df, **kwargs,style=s)
mpf.plot(df)
