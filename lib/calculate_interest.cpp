//
// Created by Yasuo Ignacio Maidana Pérez on 24/10/24.
//
#include "target_link_libraries.h"

unordered_set<float> get_payments_diff_set(const vector<float>& payments)
{
    unordered_set<float> payments_diff_set;
    for (int i = 2; i < payments.size(); i++)
    {
        if (float payment_diff = payments[i] - payments[i - 1]; payment_diff != 0)
        {
            payments_diff_set.insert(payment_diff);
        }
    }
    return payments_diff_set;
}

int type_of_user(
    const unordered_set<float>& payments_diff_set,
    const vector<float>& payments)
{
    if (payments_diff_set.empty() || payments.size() == 2)
    {
        return 0;
    }
    if (payments_diff_set.size() == 1)
    {
        return 2;
    }
    return 1;
}

int calculate_m(const unordered_set<float>& payments_diff_set, const vector<float>& payments)
{
    const float payment_diff = *payments_diff_set.begin();
    int m = -1;
    for (int i = 1; i < payments.size(); i++)
    {
        m++;
        if (payments[i] - payments[i - 1] == payment_diff)
        {
            if (m > 0)
            {
                break;
            }
        }
    }
    return m;
}

tuple<float, int, int> calculate_interest_rate_period(const int allowed_years, const vector<float>& debt,
                                                      const vector<float>& payments)
{
    float interest_rate = (debt[1] + payments[1]) / debt[0] - 1;
    const unordered_set<float> payments_diff_set = get_payments_diff_set(payments);
    int client_type = type_of_user(payments_diff_set, payments);
    const int allowed_months = allowed_years * 12;
    int remaining_payments = 0;
    float remaining_debt = debt.back();
    float last_payment = payments.back();

    if (client_type != 2)
    {
        if (remaining_debt * interest_rate >= last_payment)
        {
            return make_tuple(interest_rate, client_type, -2);
        }
        while (remaining_payments <= allowed_months && remaining_debt > 0)
        {
            remaining_payments++;
            remaining_debt = (remaining_debt - last_payment) * (1 + interest_rate);
        }
    }
    else
    {
        const int m = calculate_m(payments_diff_set, payments);
        const float increment = *payments_diff_set.begin();
        int m_i = m;
        while (remaining_payments <= allowed_months && remaining_debt > 0)
        {
            remaining_payments++;
            m_i--;
            if (m_i<0)
            {
                m_i = m;
                last_payment += increment;
            }
            remaining_debt = (remaining_debt - last_payment) * (1 + interest_rate);
        }
    }

    remaining_payments = remaining_payments > allowed_months ? -1 : remaining_payments;
    return make_tuple(interest_rate, client_type, remaining_payments);
}