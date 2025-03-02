async function getOrders(accessToken, region, marketplaceIds) {
  const ordersUrl = `https://sellingpartnerapi-${region.replace(".","")}.amazon.${region}/orders/v0/orders`;
  const params = {
    MarketplaceIds: marketplaceIds,
    CreatedAfter: '2023-01-01T00:00:00Z',
  };

  try {
    const response = await axios.get(ordersUrl, {
      headers: {
        'Authorization': `Bearer ${accessToken}`,
        'x-amz-access-token': accessToken,
        'x-amz-user-agent': 'YourAppName/1.0 (Language=JavaScript)', //Requerido pela Amazon
      },
      params: params,
    });
    return response.data;
  } catch (error) {
    console.error('Erro ao obter pedidos:', error.response ? error.response.data : error.message);
    throw error;
  }
}

//Exemplo de uso
async function main2(){
    const clientId = 'YOUR_CLIENT_ID';
    const clientSecret = 'YOUR_CLIENT_SECRET';
    const refreshToken = 'YOUR_REFRESH_TOKEN';
    const region = 'com.br'; // or com, .de, .uk, etc.
    const marketplaceIds = ["YOUR_MARKETPLACE_ID"];

    try{
        const accessToken = await getAccessToken(clientId,clientSecret,refreshToken,region);
        const orders = await getOrders(accessToken, region, marketplaceIds);
        console.log("Orders:", JSON.stringify(orders, null, 2));
    } catch (error){
        console.log("Error during main2 execution", error);
    }
}

main2();