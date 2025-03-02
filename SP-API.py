from sp_api.base import SellingApi
from sp_api.auth import AccessTokenCredential, ServicePrincipalCredential
from sp_api.base import Marketplaces

# Suas credenciais
client_id = "SEU_CLIENT_ID"
client_secret = "SEU_CLIENT_SECRET"
refresh_token = "SEU_REFRESH_TOKEN" #obtido durante o processo de autorização.
role_arn = "SEU_ROLE_ARN"
region = "us-east-1" # ou outra região, como eu-west-1 (Europa)

try:
    credentials = AccessTokenCredential(refresh_token=refresh_token, client_id=client_id, client_secret=client_secret, role_arn=role_arn)
    selling_api = SellingApi(credentials=credentials, marketplace=Marketplaces.US) #troque Marketplaces.US para outros marketplaces.

    orders = selling_api.call(
        '/orders/v0/orders',
        params={
            'MarketplaceIds': [Marketplaces.US.value],
            'OrderStatuses': ['Unshipped']
        }
    )

    if orders.payload and orders.payload['Orders']:
        for order in orders.payload['Orders']:
            print(f"ID do Pedido: {order['AmazonOrderId']}")
            # Processar os dados do pedido
    else:
        print("Nenhum pedido encontrado.")

except Exception as e:
    print(f"Erro: {e}")