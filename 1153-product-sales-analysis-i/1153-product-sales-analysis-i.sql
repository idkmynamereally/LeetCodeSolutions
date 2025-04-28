SELECT product_name, year, price
FROM Sales JOIN product
ON Sales.product_id = Product.product_id;