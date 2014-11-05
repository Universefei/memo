from django.db import models


# Create your models here.
class PriceHistory(models.Model):
    data = models.DateTimeField(auto_now_add=True)
    price = models.DecimalField(max_digits=5, decimal_places=2)
    volume = models.PositiveIntegerField()
    total_btc = models.PositiveIntegerField()

    # add later
    

