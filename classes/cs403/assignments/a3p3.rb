j = case k
when 1, 2
    2 * k - 1
when 3, 5
    3 * k + 1
when 4
    4 * k - 1
when 6, 7, 8
    5 * k + 1
else
    nil
end