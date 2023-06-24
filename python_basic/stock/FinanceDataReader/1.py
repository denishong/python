import FinanceDataReader as fdr
import mplfinance as mpf

code = 'ABT'
start_date='2021-11-01'
end_date='2021-12-10'

df=fdr.DataReader(code,start_date,end_date)
mpf.plot(df, type='candle')
