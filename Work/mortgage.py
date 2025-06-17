# mortgage.py
#
# Exercise 1.7
principal = 500000.0
rate = 0.05
payment = 2684.11
total_paid = 0.0
month = 0

extra_payment_start_month = 61
extra_payment_end_month = 108
extra_payment = 1000 

while principal > payment:
    if month < extra_payment_start_month or month >= extra_payment_end_month:
        principal = principal * (1+rate/12) - payment
        total_paid = total_paid + payment
    else:
        principal = principal * (1+rate/12) - payment - extra_payment
        total_paid = total_paid + payment + extra_payment 
    month += 1
    # print(month, round(total_paid, ndigits=2), round(principal, ndigits=2))
    print(f'{month:^15} {round(total_paid, ndigits=2):^15} {round(principal, ndigits=2):^15}')

payment = principal
total_paid = total_paid + payment
month += 1
# print(month, round(total_paid, ndigits=2), round(principal, ndigits=2))
print(f'{month:^15} {round(total_paid, ndigits=2):^15} {round(principal, ndigits=2):^15}')